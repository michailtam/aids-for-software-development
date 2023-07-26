" IMPORTANT: For more available options you can write in command mode :help option-list or :options.

" Enable specific plugins
" IMPORTANT: To install plugins previously a plugin manager has to be installed based on the following tutorials.
" In general, it is recommended to use a plugin manager and not installing the plugins manually (because of updates).
" https://opensource.com/article/20/2/how-install-vim-plugins
" https://www.youtube.com/watch?v=2prsFrKwbOo&t=313s
" After downloading and saving the plugin execute :PlugInstall in vim to
" enable the plugin.

" Tutorials of how to turn vim into a C++ IDE: 
" https://idorobotics.com/2018/04/01/setting-up-vim-for-c-development/
" https://www.quora.com/How-to-build-vim-editor-in-Linux-into-an-effective-C++-programming-IDE

call plug#begin('~/.vim/plugged')
" General plugins for the vim editor
Plug 'preservim/nerdtree'					" File explorer for vim
Plug 'jistr/vim-nerdtree-tabs'		" Makes NERDTree feel like a true panel, independent of tabs
Plug 'ervandew/supertab'					" Enables <Tab> insert completion
Plug 'vim-airline/vim-airline'		" Displays the status of the plugin-loading
Plug 'terryma/vim-multiple-cursors' " Enables multiple selection
Plug 'mileszs/ack.vim'						" Searches for a file which contains a certain line or a certain word
Plug 'junegunn/fzf.vim'						" Intelligent search for filenames. Type :FZF to start searching
Plug 'altercation/vim-colors-solarized' " Vim colorschemes
Plug 'junegunn/goyo.vim'					" Centers the text in the editor
Plug 'ctrlpvim/ctrlp.vim'         " File findings
Plug 'mbbill/undotree'            " Visualizes the undo history
Plug 'jremmen/vim-ripgrep'        " Searches the entire system using a pattern

" C++-specific plugins
Plug 'cquery-project/cquery',			" C++ indexation
Plug 'preservim/nerdtree'					" File explorer for vim
Plug 'ycm-core/YouCompleteMe', {'for': ['cpp', 'c', 'h', 'cmake']} " Code completion for C++
Plug 'vim-syntastic/syntastic',{'for': ['cpp', 'c', 'h', 'cmake']}	" Syntax checking for C++
Plug 'majutsushi/tagbar', 		 {'for': ['cpp', 'c', 'h', 'cmake']}	" Tags for C++ code
Plug 'vim-scripts/a.vim',			 {'for': ['cpp', 'c', 'h', 'cmake']}	" Commands to switch between source and header files
Plug 'xavierd/clang_complete', {'for': ['cpp', 'c', 'h', 'cmake']}	" C and C++ code completion
Plug 'preservim/nerdcommenter',{'for': ['cpp', 'c', 'h', 'cmake']}	" Comment functions
Plug 'cquery-project/cquery',	 {'for': ['cpp', 'c', 'h', 'cmake']}	" C++ indexation
Plug 'gilligan/vim-lldb',      {'for': ['cpp', 'c', 'h', 'cmake']}	" Enables a debugger
" ADDITIONAL Plugins for C++: https://www.quora.com/How-to-build-vim-editor-in-Linux-into-an-effective-C++-programming-IDE 

" General plugins for coding
Plug 'LucHermitte/lh-vim-lib'     " Defines some common vim functions
Plug 'LucHermitte/local_vimrc'    " Applies settings on files from the same project
Plug 'tpope/vim-fugitive'					" Git plugin
Plug 'airblade/vim-gitgutter'			" Shows a git diff in the sign column
Plug 'LucHermitte/vim-refactor'		" Enables refactoring
Plug 'vim-scripts/taglist.vim'		" Makes finding variables, types, classes and functions in the code easier
Plug 'frazrepo/vim-rainbow',	{'for': ['cpp', 'c', 'h', 'py', 'cmake']}			" Shows different colors for the brackets
"Plug 'mattn/emmet-vim'						" Plugin for html
Plug 'majutsushi/tagbar'					" Easy way to browse tags
Plug 'SirVer/ultisnips'						" Provides ready code snippets e.g. for classes
Plug 'Townk/vim-autoclose'				" Provides autoclose when typing a character (similar to autocompletion)
call plug#end()

" Gets setup to search from the root of the project
if executable('rg')
  let g:rg_derive_root='true'
endif

" Plugin configurations
let g:clang_library_path='/usr/lib/llvm-6.0/lib/libclang.so'
let g:rainbow_active = 1
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
let g:nerdtree_tabs_open_on_console_startup=1

"let g:syntastic_always_populate_loc_list = 1
"let g:syntastic_auto_loc_list = 1
"let g:syntastic_check_on_open = 1
"let g:syntastic_check_on_wq = 0

" VIM STARTUP
autocmd vimenter * NERDTree
autocmd vimenter * vertical resize 25
autocmd vimenter * wincmd l       " Sets the focus on the right window

" KEY MAPPINGS
let mapleader = "."          " Sets the leader key (here to Ctrl)
nmap <F6> :NERDTreeToggle<CR> "Toggles the navigation on and off
nmap <S-Tab> :<ESC>gt
nmap <--Tab> :<ESC>gT
nnoremap <C-Left> :<ESC><C-W>h    " Moves to the left window
nnoremap <C-Right> :<ESC><C-W>l   " Moves to the right window
nnoremap <C-Down> :<ESC><C-W>j    " Moves to the below window
nnoremap <C-Up> :<ESC><C-W>k      " Moves to the up  window
nnoremap <silent> <Leader>v :NERDTreeFind<CR>
nnoremap <C-U> :UndotreeShow<CR>  " Opens the undo tree window
nnoremap <silent> <Leader>v :NERDTreeFind<CR>
nnoremap <silent> <Leader>+ :vertical resize +5<CR>
nnoremap <silent> <Leader>- :vertical resize -5<CR>
nnoremap <silent> <Leader>gt :YcmCompleter GoTo<CR> " Proceeds to the definition
nnoremap <silent> <Leader>gf :YcmCompleter FixIt<CR> 

" Editor settings
set number relativenumber
set splitbelow splitright 				" In case of splitting this gets done by the setting

set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

" Setup the encoding
set enc=utf-8                                                               " Set UTF-8 encoding
set fenc=utf-8
set termencoding=utf-8
set nocompatible

set history=500 							" Sets the history to 100 (default is 50) 
set tabstop=2 softtabstop=2 	" Sets the tabstop
set shiftwidth=2 							" Sets the shift width
set ruler 										" Shows the position of the cursor
set showcmd 									" Show incoplete commands
set wildmenu 									" Displays a menu at the bottom of the screen while searching with tab-comletion.
set scrolloff=5 							" Minimum lines above the curser (you can position the text with z-ENTER)
set hlsearch 									" Higlights the previous search match 
set incsearch 								" This ignores the case while searching
set ignorecase                " Ignores case sensitivity while searching 
set smartcase                 " Case sensitive searching until a capital letter gets inserted
set number 										" Displays the number of a line
set nobackup 									" Prevents from  backup the file before saving it
set noswapfile                " Prevents of creating a swap file of the file
set undodir=~/.vim/undodir    " Sets the directory for undo operations (has to be created manually)
set undofile                  " Sets the undo profiler
set lbr 											" Preserves breaking mid words e.g. ca -> and t is on the next line
set ai 												" ai: Does autointent based on the previous line
set si 												" si: Does smart intent e.g. sets the intent of the closing braicket 
set bg=dark 									" Tells vim to match the colors based on the background
set smartindent 							" Enables the smart indentation
set expandtab 								" Converts tabs to spaces
set nowrap                    " Prevents of wrapping to the next line if out of screen

" Sets the color sheme. To make this working you have to create a directory colors in ~/.vim/ and copy the .vim " colorscheme file inside.
" IMPORTANT: In case of the following error message:
" E488: Trailing Characters error after attempting to install vim-hybrid
" you have to download the coloscheme .vim file and replace the content with the raw text of the
" github repo. For example the content of the downloaded simple-dark.vim file has to be replaced with the 
" raw text content of the github repo, to prevent copying the html tags.
syntax on
colorscheme simple-dark 

" MODE LINE: Forces vim to treat the following file types as they are set to
" vim: set ft=vim :
" vim: set ft=cpp :
" vim: set ft=c :
" vim: set ft=txt :
" vim: set ft=h :
