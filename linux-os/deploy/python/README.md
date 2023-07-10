# How to create your own Python library
This guide describes how you can create and build your own Python library (April 2022).
The guide is based on the post at [medium](https://medium.com/analytics-vidhya/how-to-create-a-python-library-7d5aea80cc3f) (I have created a pdf 'How to create a Python library.pdf' if you can't reach the original post). The creation process gets 
described based on the Ubuntu 20.04.LTS operating system. So let's start.

## 1. Create a virtual environment
In general, it is recommended to create virtual environments and install there all your packages. There are three ways of how
you can create a virtual environment. 
1. Using [pip](https://docs.python.org/3/library/venv.html)
3. Using [miniconda](https://docs.conda.io/projects/conda/en/latest/user-guide/install/linux.html)

For our case we create a virtual environment usint miniconda (i.e. conda). We choose miniconda because it is a free minimal installer for conda. It is a small, bootstrap version of Anaconda that includes only conda, Python, the packages they depend on, and a small number of other useful packages, including pip, zlib and a few others.

`$ conda create -n cv-env` This creates a virtual environment named cv-env (i.e. computer vision). You can also specify the python version the virtual environment will use with `$ conda create -n cv-env python=x.x` where x.x is the python verison number (e.g. 3.9).

When the process has finished check if the environment was created properly by issuing `$ conda env list`. After that, activate it with `$ conda activate cv-env`.

## 2. Install all your python packages
After creating the virtual environment we now need to install all the packages that we want to use. In our case, we need
opencv-contrib-python, matplotlib, The installation process takes some time so be patient.

1. `$ conda install matplotlib`
2. `$ pip install opencv-contrib-python` or `$ pip install opencv-python`

To check if the packages were installed issue `$ conda list` or if you want to look for a specific package `$ conda list | grep matplotlib`

**Install the following packages which are needed to create the library**
```
$ pip install wheel
$ pip install setuptools
$ pip install twine
```

It is recommended to test your library before you deploy or use it on another system. For this, you have to install the following packages:
```
$ pip install pytest==4.4.1
$ pip install pytest-runner==4.4
```

**NOTE:** If you want to uninstall a package you need to use the same uninstaller `$ pip uninstall pkg_name` or `$ conda remove pkg_name`. In both cases you need to be in the virtual environment. 


## 3. Create the library folder and its content
Now, it is time to create our library folder and create all the files we want to include. In our case, we create a folder library named cvlib and include some custom created files for displaying a color image and a grayscale image side-by-side.
Our folder structure looks like this:

<pre><font color="#3465A4"><b>cvlib/</b></font>
├── <font color="#3465A4"><b>help</b></font>
│   ├── __init__.py
│   └── plotting.py
├── <font color="#4E9A06"><b>__init__.py</b></font>
├── README.md
└── <font color="#3465A4"><b>test_py</b></font>
    ├── __init__.py
    ├── <font color="#75507B"><b>street1.jpg</b></font>
    └── <font color="#4E9A06"><b>test_cv.py</b></font>
</pre>

## 4. Create the setup.py file to build the library
To be able to build the library we have to create a **setup.py** file which includes all the fields to build the library. This file must be created in the root folder of the library folder. In our case it is the root folder of the cvlib folder.

```
from setuptools import find_packages, setup

setup(
    name='cvlib',
    packages=find_packages(include=['cvlib', 'cvlib.*']),
    version='0.1.0',
    description='Small Computer Vision Library',
    author='Michail',
    license='GPL',
    install_requires=[],
    setup_requires=['pytest-runner'],
    tests_require=['pytest==4.4.1'],
    test_suite='test_py',
)
```
### Explanation of the important fields
- **name**: The name of the library root folder
- **packages**: Here you need to include all your packages i.e. for our purpose cvlib and all included sub-packages. To transform a file to a package you need to create in the directory an empty (two underscores)init(two underscores).py file.
- **descriptor**: Describes in some words what the library is about
- **setup_requires**: This includes the test pytest-runner package installed previously
- **test_suite**: This is the folder where each test file is located. By issuing `$ python setup.py pytest` every test file in this folder gets executed. Keep in mind to name your test-file beginning with test_... otherwise it will not be located.

To get an overview of all fields please refer to the documentation of how to write a [setup script](https://docs.python.org/3/distutils/setupscript.html).

## 5.Build and install the library
In this final step we have to build our library so it can be used in other projects in the future. For this, we have to change in the root folder (where the setup.py file is located) and issue the following:
```
$ python setup.py bdist_wheel
```
This creates the library and stores it in the **dist** folder
<pre>── <font color="#3465A4"><b>dist</b></font>
│   └── cvlib-0.1.0-py3-none-any.whl
</pre>

### Install the library
To install the library you have to execute pip with the created wheel which is located in the **dist** folder. 
`pip install dist/cvlib-0.1.0-py3-none-any.whl`. After that, check if the library was installed properly in your
virtual environment.

`$ pip list | grep cvlib` or `$ conda list | grep cvlib`

### The output should look like this
> $ cvlib                     0.1.0                    pypi_0    pypi

To remove the installed environment you have to issue `pip uninstall cvlib`.

## Deploy the library
Now you only need to include the library in a python project. For simplicity, try the following which shouldn't
output any error `$ python3 `

<pre>Python 3.9.12 | packaged by conda-forge | (main, Mar 24 2022, 23:25:59) 
[GCC 10.3.0] on linux
Type &quot;help&quot;, &quot;copyright&quot;, &quot;credits&quot; or &quot;license&quot; for more information.
&gt;&gt;&gt; import cvlib
&gt;&gt;&gt; 
</pre>

or change into the **test_py** folder and execute the python script.

<pre>$ python3 test_cv.py</pre>

![screenshot](/linux-os/deploy/python/cvlib/test_py/screenshot.png)

### Generate a requirements.txt file for any project based on imports
If you don't want to install every package by hand, you need to create a **requirements.txt** file which includes all the packages. If you want to know how you can create the txt file you can look [here](https://pip.pypa.io/en/stable/cli/pip_install/#requirement-specifiers) and [here](https://note.nkmk.me/en/python-pip-install-requirements/). For simplicity, there is a program named [pipreqs](https://github.com/bndr/pipreqs) which executes the creation of the file automatically and can be installed be issuing: `$ pip install pipreqs`. Then change into the project root folder **cvlib** and execute `$ pipreqs .` which creates the requirements.txt file in the current folder. The content of the file looks like this:

<pre>$ cat requirements.txt 
matplotlib==3.5.1
numpy==1.22.3
opencv_contrib_python==4.5.5.64
</pre>

As expected in our case there are three required packeges with their version numbers which will be installed automatically if we issue `$ pip install -r requirements.txt`.
