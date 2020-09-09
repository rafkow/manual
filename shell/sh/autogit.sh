#!/bin/bash
cd c:\\Users\\rkowalewski\\manuals\\
git add .
commmit_msg='update_'$(date +'%d/%m/%Y')
git commit -m ${commmit_msg}
git push
