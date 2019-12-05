#!/usr/bin/env bash

# =============================================================================
# File Name: update.sh
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Thu 21 Nov 2019 01:15:08 PM CST
# =============================================================================


set -x


git add .
git commit -m "$(git status -s)"
git push origin master

