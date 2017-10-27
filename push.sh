git add -A
set /p commit="commit infomation:" 
git commit -m %commit%
git push