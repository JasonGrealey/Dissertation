g++ $(pwd)"/main.cpp"
./a.out
$(pwd)"/./a.out"
touch ~/.bashrc
echo "alias run="\'""$(pwd)"/./run.sh""'" >> $HOME"/.bashrc"
source ~/.bashrc
