#!/bin/bash
git config --global alias.st status
git config --global alias.gst "git status"

git config --global alias.ci commit

git config --global alias.co checkout
git config --global alias.gco "git checkout"

git config --global alias.br branch
git config --global alias.gbr "git branch"

git config --global color.ui true
git config --global alias.s-log "log --pretty=oneline"
git config --global alias.f-log "log --pretty=fuller"
git config --global alias.c-df "diff --cached"
git config --global alias.h-df "diff HEAD"
git config --global push.default simple
git config --global user.name "ElephantKing"
git config --global user.email "bupt_shufeng@163.com"

cp ./.vimrc ~/ && cd && source .vimrc && cd -
