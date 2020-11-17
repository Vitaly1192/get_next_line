set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')
Plugin 'vim-airline/vim-airline'				"Улучшенная строка состояния
Plugin 'ErichDonGubler/vim-sublime-monokai' "Устанавливаем цветовые темы
Plugin 'pandark/42header.vim'
Plugin 'pbondoer/vim-42header'
" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
" Plugin 'L9'
" Git plugin not hosted on GitHub
Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
" Plugin 'ascenator/L9', {'name': 'newL9'}

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
set number		"Нумерация строк
set t_Co=256	" использовать больше цветов в терминале "
set laststatus=2 " всегда показывать строку состояния "
set et "включим автозамену по умолчанию "
set ai "включим автоотступы для новых строк"
set cin " включим отступы в стиле Си"
set autoread "автоматически обновлять файл при его изменении"
set cursorline "подсвечивание строки. на которой находится курсов
syntax enable "Включает подсветку синтаксиса
let g:airline_powerline_fonts = 1	"Включить поддержку Powerline шрифтов 
colorscheme sublimemonokai "Установка цветовой темы. Можно поставить другую, список богат
set mouse=a
set mousemodel=popup
set colorcolumn=80
set tabstop=4		"Количество пробелов в одном обычном табе
set softtabstop=4	"Количество пробелов в табе при удалении
set shiftwidth=4
set noexpandtab		"Это запрет на  замену таба на пробел
set foldcolumn=2	"Небольшой отступ между левой частью окна
set noerrorbells	"отлючение звука
set novisualbell	"Это тоже
nmap <f1> :FortyTwoHeader<CR> "Это что-то вроде alia. nmap - нормальный режим 
"autocmd FileType htmldjango let b:fortytwoheader_delimiters=['{#', '#}', '*']
