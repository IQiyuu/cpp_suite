# CPP MAKER

### What is it ?
Cpp maker is a simple bash script who create basics for your cpp project including:
    * simple Makefile.
    * srcs folder for your sources files (.cpp).
    * headers folder for your headers files (.hpp/.h).
    * a simple main.
    * basic classes in canonical form of coplien.
    * simple header for your classes.

### How to use it ?
First you have to copy the script 'cpp_maker' into the your project folder.
Then exec it with ./cpp_maker.sh
Cpp maker take at least 2 args.

The first one is the name of your exec file for the Makefile.
All others are your classes.

[For exemple `./cpp_maker.sh test_exec Class1 Class2` will create a that:](https://github.com/IQiyuu/cpp_maker/assets/example.png)

The script will not delete/overwrite your files if they already exists, but he will ask if you want to overwrite.

#### Arguments !
    * -y will not ask to overwrite files so be sure befor using this.
    * -c will compile your program using make
    * -e will compile and execute your program using make r (make + ./exec)
    * -v with this arg you can now add variables into your classes.

##### About -v /!\
-v doesn't check anything at all ! if you enter int and you put "hello" your variable in your classe cpp will be initialized with "hello".

Plus for containers and string you don't have don't write "std::string". 'std::' will be added automatically so write string vector<type> (type is the vector type like int, string...).

same for initialization string don't need '""' => type: string, name: _name, value: Jim. So logically containers will be initialized empty so your input will be ignored (std::list<int> name = new std::list<int>()).
