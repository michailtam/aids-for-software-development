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