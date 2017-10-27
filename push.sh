git add -A
echo  "commit infomation:"
read commitInfo 
git commit -m "$commitInfo"
git push
