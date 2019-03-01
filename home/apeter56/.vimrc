:syntax on

" begin plugins (VundleVim/Vundle.vim) git repo
set nocompatible
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'VundleVim/Vundle.vim' " Vundle
Plugin 'vim-scripts/vim-auto-save' "auto-save
" vim +PluginInstall +qall to install new plugins

call vundle#end()
filetype plugin indent on
" end plugins

set t_kb=
set nocompatible
set backspace=eol,indent,start
set autoindent
set smartindent

" don't highlight the last search upon startup
set viminfo="h"

" Do C-style auto indentation on C/C++/Perl files only :)
:filetype on
:autocmd FileType c,cpp,perl :set cindent

" stop Vim from beeping all the time
set vb

set tabstop=4
set shiftwidth=4
set softtabstop=4
set smarttab

" uncomment to insert spaces instead of a tab when tab is pressed
"set expandtab

set ruler
set background=dark

"Tell you if you are in insert mode
set showmode

"match parenthesis, i.e. ) with (  and } with {
set showmatch

"ignore case when doing searches
set ignorecase
set smartcase

"tell you how many lines have been changed
set report=0

set scrolloff=5
set wildmode=longest,list
set incsearch
set hlsearch

:colorscheme elflord

set showtabline=2
set number " Line Numbers
set mouse=a " Mouse Movement
set t_vb= "Fix annoying end and begining of file flashing
let g:auto_save = 1 " Enable Autosave on startup

" au VimEnter * silent! !xmodmap -e "clear lock" -e "keycode 0x42 = Escape"
" au VimLeave * silent! !xmodmap -e "add lock" -e "keycode 0x42 = Caps_Lock"

set t_Co=256
set background=dark
colorscheme molokai
highlight Normal ctermbg=NONE
highlight nonText ctermbg=NONE

