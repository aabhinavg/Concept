#set -x
clear
LINK=https://in.linkedin.com/in/abhinav-tiwari-040894148
CDIR=`pwd`
echo "\nyou can find all your build inside $CDIR/build\n"

if [ -d "$CDIR/build" ]
then
       echo "Directory exists $CDIR/build" 
       echo "Removing the diretory"
       rm -r $CDIR/build
fi      

mkdir  $CDIR/build


echo "scirpt running for creating a shared library\n\n"
echo "Wait for two second"
sleep 2
clear 
echo "You can see the below source code 
      Where main function -> value_to_be_printed(int)\n\n"
echo "=======================================================\n"
cat $CDIR/main.cpp
echo "=======================================================\n"
sleep 3
echo "Defination of the function value_to_be_printed(int) is 
      inside library.cpp for which we are going to create shared library
      which will be linked with the main during runtime\n"
      
echo "=======================================================\n"
cat $CDIR/library.cpp
echo "=======================================================\n"
sleep 3
echo "Step 1 : compile the code above into an object file.\n\n"
echo "--------------------------------------------"

echo "g++ -fPIC -c -Wall library.cpp -o library.o"

echo "--------------------------------------------"

g++ -fPIC -c -Wall library.cpp -o $CDIR/build/library.o
ls | grep library.o
sleep 3
echo "This command will create a library.o in the  working directory\n"
sleep 2
echo "-fPIC: enables the address of shared libraries to be relative so that the executable is independent of the position of libraries.\n"
sleep 2
echo "-c :  will create object file\n"
sleep 2
echo " Wall: enables all compiler's warning messages. This option should always be used, in order to generate better code\n"
sleep 8
clear
echo "Step 2: Create shared library\n"
echo "-----------------------------------------------"
sleep 2
echo "g++ -shared library.o -o liblibrary.so"
sleep 2
echo "-----------------------------------------------\n\n"
echo "He hahaha !!  Shared library created by you !! Give me party  🙂 \n "
sleep 2
g++ -shared $CDIR/build/library.o -o $CDIR/build/liblibrary.so
ls $CDIR/build | grep liblibrary.so
sleep 2
echo "shared :"
	echo "Produce a shared object which can then be linked with other objects to form
an executable. Not all systems support this option. For predictable results,
you must also specify the same set of options used for compilation (‘-fpic’,
‘-fPIC’, or model suboptions) when you specify this linker option"
sleep 12

clear
echo "Step 3: You want to use that shared library created by you\n"
echo "------------------------------------------------"

echo "g++ -Wall main.cpp -L"$CDIR/build "-llibrary"

echo "------------------------------------------------\n"

cd $CDIR/build
g++ -Wall $CDIR/main.cpp  -L$CDIR/build -llibrary -o $CDIR/build/out
ls
echo "export LD_LIBRARY_PATH=$CDIR/build:$LD_LIBRARY_PATH"
export LD_LIBRARY_PATH=$CDIR/build:$LD_LIBRARY_PATH
sleep 8

ls $CDIR/build | grep out
echo "out file is created you can execute it now\n"
clear
echo "--------------------------------------------"
echo  "./out"
echo "--------------------------------------------\n"
$CDIR/build/out
sleep 7
clear
echo " All shared required by the out file created by you\n"
echo "======================================================="
echo "ldd $CDIR/build/out\n"
echo "======================================================\n"
 ldd $CDIR/build/out
 sleep 8
clear
echo "\nYou can see that your shared library liblibrary.so is required by out\n"
echo "=====================================\n"
ldd $CDIR/build/out | grep liblibrary.so
echo "======================================\n"
sleep 8
clear
echo "Let see the function value_to_be_printed is their inside library or not\n"

echo "nm liblibrary.so | grep value_to_be_printed"

echo "_____________________________________________\n"

nm liblibrary.so | grep value

echo "_______________________________________________\n"

echo "Hurrah you have finded it inside T means text section"
sleep 8
clear
echo "Lets check in your executable where value_to_be_printed is present or not"

echo "nm out | grep value_to_be_printed \n"
echo "__________________________________________________\n"

nm out | grep value_to_be_printed

echo "__________________________________________________\n"
echo "It say U means undefined"
sleep 8
clear
echo "It proof that value_to_be_printed get it defination when we execute out"
echo "i.e. during run time shared library dependencies get resolve"
echo "\nyou can find all your build inside $CDIR/build\n"

echo "\n Follow for more such tutorial\n"
sleep 2
xdg-open $LINK

