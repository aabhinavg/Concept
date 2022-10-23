**Creating Shared Library**
- Let us assume we want to be a shared library in linux with the name liblibrary.so.
- After creating a shared library we want to use its function inside our source code.
- Let the file [library.cpp](https://github.com/aabhinavg/Concept/tree/main/Shared/library.cpp) is to 
  be created as shared library with the name liblibrary.so.
- File [main.cpp](https://github.com/aabhinavg/Concept/tree/main/Shared/main.cpp) is going to use [library.cpp](https://github.com/aabhinavg/Concept/tree/main/Shared/library.cpp) file.


**Step 1:- Creating a Position-Independent Object Code**
- To build a shared library liblibrary.so for our sample function inside file [library.cpp](https://github.com/aabhinavg/Concept/tree/main/Shared/library.cpp) we invoke compiler and linker with different flags.
<div class="highlight-c notranslate"><div class="highlight"><pre><span></span><span class="cp"> linux> g++ -c -fPIC library.cpp -o library.o
  The -fPIC flag says to compiler to generate Position-independent-Code 
  The -c flag to create the object code.
  
  This step will create a Position-Independent-Object-Code and store the output in library.o</pre></span>

**Step 2 Creating a Shared library from Object Code**
- This step will create a shared library from the object code.
<div class="highlight-c notranslate"><div class="highlight"><pre><span></span><span class="cp"> linux> g++ -shared library.o  -o liblibrary.so
  The -shared flag direct the linker to create a shared object file.We will link it to our main.cpp file 
  
  This step will create a shared library with the name liblibrary.so</pre></span>


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ![Input_Output](https://github.com/aabhinavg/)




**Step 3 Linking The Shared Library**
- Once shared library creation is done we have to then link it with our main.cpp file.

<div class="highlight-c notranslate"><div class="highlight"><pre><span></span><span class="cp">
linux> g++ main.cpp ./liblibrary.so -o out
       ./out
       Calling the shared library
      inside  shared library
      10
      Completed
      </pre></span>
      
***Hurrah ! You completed shared library and link with it your source file***

____________________________________________________________________________________________________

**All Shared library Required by out**
<div class="highlight-c notranslate"><div class="highlight"><pre><span></span><span class="cp">
linux> ldd out
  linux-vdso.so.1 (0x00007ffd57a83000)
	./liblibrary.so (0x00007f9f247b0000) #created by us
	libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f9f24577000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f9f2434f000)
	libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f9f24268000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f9f247bc000)
	libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f9f24248000)
    </pre></span>

  
**Creating Shared Library Using Makefile**
- You can find the Makefile
<div class="highlight-c notranslate"><div class="highlight"><pre><span></span><span class="cp">
linux> make help
make clean      - Remove generated files
make all        - Create shared library
make            - Create shared library
make use_shared - Create executable using shared library
make execute    - Execute the executable which is created using shared library
follow step make;make use_shared;make execute
All things are created inside /home/rejvik/exp/clone/Concept/Shared/binaries</pre></span>

**Using Shell script**
- You can see all the steps required to build a shared library in automated way.
- Just run the script shared.
<div class="highlight-c notranslate"><div class="highlight"><pre><span></span><span class="cp">
linux> sh shared.sh</pre></span>

___________________________________________________________________

*****Follow on*****
[<img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white">](https://www.linkedin.com/in/abhinav-tiwari-040894148)
 








