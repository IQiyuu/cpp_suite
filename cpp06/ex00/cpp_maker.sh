#!/bin/bash

compile=false
exec=false
accept_all=false
variable=false

# Traitement des options
while getopts ":cyev" opt; do
  case ${opt} in
    c )
      compile=true
      ;;
	e )
      exec=true
      ;;
	y )
     accept_all=true
      ;;
	v )
     variable=true
      ;;
    \? )
      echo "Invalid option: -$OPTARG" 1>&2
      ;;
    : )
      echo "Invalid option: -$OPTARG requires an argument" 1>&2
      ;;
  esac
done
shift $((OPTIND -1))

# wait y or n.
$accept_all || confirm()
{
	read -r -p "${1} [y/N] " response

	case "$response" in
		[yY][eE][sS]|[yY]) 
			true
			;;
		*)
			false
			;;
	esac
}

# creating the Makefile, can be pesonalized.
createMakefile()
{
	if [ $# -ge 2 ]
	then
		echo "NAME = $1" > Makefile
		echo >> Makefile
		echo "FILES =	main\\" >> Makefile
		shift
		for param in $@; do
			echo "		$param\\" >> Makefile
		done
		
	else
		echo "Need more parameters. You should at least give the program name and one class."
		return 0
	fi
	echo >> Makefile
	echo "SRC = \$(foreach f, \$(FILES), srcs/\$(f).cpp)
OBJ = \$(SRC:.cpp=.o)

CFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g -Iheaders

all: \$(NAME)
r: re
	./\$(NAME)

\$(NAME): \$(OBJ)
	c++ \$(OBJ) \$(CFLAGS) -o \$(NAME)

.cpp.o:
	c++ -o \$@ -c $< \$(CFLAGS)

clean:
	rm -rf \$(OBJ)

fclean: clean
	rm -rf \$(NAME)

re: fclean all" >> Makefile

}

# Create the main.cpp.
createMain()
{
	include_content=""
	class_creating=""
	class_delete=""
	i=0

	touch main.cpp
	shift
	for param in $@; do
		include_content+="#include \"$param.hpp\""$'\n'
		class_creating+="	$param *v$i = new $param();"$'\n'
		class_delete+="	delete v$i;"$'\n'
		((i+=1));
	done
	echo "$include_content" > main.cpp
	echo "int main( int, char ** ) {" >> main.cpp
	echo "$class_creating" >> main.cpp
	echo "$class_delete" >> main.cpp
	echo "	return 0;
}" >> main.cpp
}

# Create all other files.
createFile()
{
	cpp_file="srcs/$1.cpp"
	hpp_file="headers/$1.hpp"

	declare -A variables

	i=0
	
	if $variable; then
		while true; do
			read -r -p "Type of your variable for $1 (or '' to stop) : " user_input
			if [ "$user_input" = "" ]; then
				echo "Creating file $hpp_file..."
				break
			fi;
			case "$user_input" in
				"list"|"string"|"vector"|"stack"|"map"|"array"|"queue"|"deque"|"set")
					user_input="std::$user_input"
					;;
			esac;
			variables["$i,0"]="$user_input"
			read -r -p "Name of your variable : " user_input
			variables["$i,1"]="$user_input"
			read -r -p "Base value of your variable : " user_input
			variables["$i,2"]="$user_input"
			if [ ${variables["$i,0"]} == "std::string" ]; then
				variables["$i,2"]="\"$user_input\""
			fi
			((i+=1));
		done;
	fi

	# hpp file
	if [ ! -f $hpp_file ] || $accept_all || confirm "$1.hpp already exist do you want to replace ?";
	then
		echo "#ifndef ${1^^}_HPP" > $hpp_file
		echo "# define ${1^^}_HPP" >> $hpp_file
		echo >> $hpp_file

		echo "#include <iostream>" >> $hpp_file
		echo >> $hpp_file

		echo "class $1 {" >> $hpp_file
		echo "	private:" >> $hpp_file
		for ((j=0; j<i; j++)); do
			echo "		${variables["$j,0"]}	${variables["$j,1"]};" >> $hpp_file
		done
		echo >> $hpp_file

		echo "	public:" >> $hpp_file
		echo "		$1( void );" >> $hpp_file
		echo "		$1( const $1 & );" >> $hpp_file
		echo "		$1	&operator=( const $1 & );" >> $hpp_file
		echo "		~$1( void );" >> $hpp_file
		if [ $i -ne 0 ]; then
			echo >> $hpp_file
		fi
		for ((j=0; j<i; j++)); do
			echo "		${variables["$j,0"]}		get${variables["$j,1"]^}( void ) const;" >> $hpp_file
			echo "		void	set${variables["$j,1"]^}( ${variables["$j,0"]} & );" >> $hpp_file
		done

		echo >> $hpp_file
		echo "};" >> $hpp_file
		echo >> $hpp_file
		echo "#endif" >> $hpp_file

		chmod 777 $hpp_file
	fi

	# cpp file
	if [ ! -f $scpp_file ] || $accept_all || confirm "$1.cpp already exist do you want to replace ?";
	then
		echo "Creating file $cpp_file..."

		echo "#include \"$1.hpp\"" > $cpp_file
		echo >> $cpp_file

		echo -n "$1::$1( void )" >> $cpp_file
		if [ $i -ne 0 ]; then
			echo -n ": " >> $cpp_file
			for ((j=0; j<i; j++)); do
				echo -n "${variables["$j,1"]}(${variables["$j,2"]})" >> $cpp_file
				echo "$i-$j"
				if [ "$j" -lt $((i - 1)) ]; then
					echo -n ", " >> $cpp_file
				fi
			done
		fi
		echo " {" >> $cpp_file
		echo "	std::cout << \"$1 \033[32mcreated.\033[0m\" << std::endl;" >> $cpp_file
		echo "}" >> $cpp_file
		echo >> $cpp_file

		echo -n "$1::$1( const $1 &ref )" >> $cpp_file
		if [ $i -ne 0 ]; then
			echo -n ": " >> $cpp_file
			for ((j=0; j<i; j++)); do
				echo -n "${variables["$j,1"]}(ref.${variables["$j,1"]})" >> $cpp_file
				if [ "$j" -lt $((i - 1)) ]; then
					echo -n ", " >> $cpp_file
				fi;
			done;
		fi
		echo " {" >> $cpp_file
		if [ $i -eq 0 ]; then
			echo "	(void)ref;" >> $cpp_file
		fi
		echo "	std::cout << \"$1 \033[32mcopy created.\033[0m\" << std::endl;" >> $cpp_file
		echo "}" >> $cpp_file
		echo >> $cpp_file

		echo "$1	&$1::operator=( const $1 &ref ) {" >> $cpp_file
		if [ $i -ne 0 ]; then
			for ((j=0; j<i; j++)); do
				echo "	this->${variables["$j,1"]} = ref.${variables["$j,1"]};" >> $cpp_file
			done
		else
			echo "	(void)ref;" >> $cpp_file
		fi
		echo "	std::cout << \"$1 \033[32mcopy created.\033[0m\" << std::endl;" >> $cpp_file
		echo "	return *this;" >> $cpp_file
		echo "}" >> $cpp_file
		echo >> $cpp_file

		echo "$1::~$1( void ) {" >> $cpp_file
		echo "	std::cout << \"$1 \033[31mdeleted.\033[0m\" << std::endl;" >> $cpp_file
		echo "}" >> $cpp_file

		for ((j=0; j<i; j++)); do
			echo >> $cpp_file
			echo "${variables["$j,0"]}	$1::get${variables["$j,1"]^}( void ) const {" >> $cpp_file
			echo "	return this->${variables["$j,1"]};" >> $cpp_file
			echo "}" >> $cpp_file
			echo >> $cpp_file
			echo "void	$1::set${variables["$j,1"]^}( ${variables["$j,0"]} &n_value ) {" >> $cpp_file
			echo "	this->${variables["$j,1"]} = n_value;" >> $cpp_file
			echo "}" >> $cpp_file
		done
		chmod 777 $cpp_file
	fi
}

echo "$accept_all"

if [ ! -f Makefile ] || $accept_all || confirm "Makefile already exist do you want to replace ?"
then 
	createMakefile $@
	chmod 777 Makefile
	echo "Makefile created."
fi

if [ ! -d srcs ]
then
	mkdir srcs
	chmod 777 srcs
	echo "folder srcs created."
fi

if [ ! -d headers ]
then
	mkdir headers
	chmod 777 headers
	echo "folder headers created."
fi

cd srcs

if [ ! -f main.cpp ] || $accept_all || confirm "Makefile already exist do you want to replace ?";
then
	createMain $@
	chmod 777 main.cpp
	echo "main created."
fi

cd ..

shift
for param in $@; do
	createFile $param
	echo "$param.(cpp/hpp) created."
done

if [ "$compile" = true ]; then
  make
fi

if [ "$exec" = true ]; then
  make r
fi
