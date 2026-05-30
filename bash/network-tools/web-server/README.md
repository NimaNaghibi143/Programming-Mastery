# We are building a web server from scratch in bash

## The overview

>[!IMPORTANT]
>before we start, i want to send my best regards to ysap.sh.

The main challenge is to build this from scratch without using soc or nc!.

> [!NOTE]
> To use bash builtins at run time like accept which is not the part of a normal bash interface. we cloned the bash resource.

### Let's talk about accept

It is a bash extension written in C. internally it uses OS networking syscalls.

Follow the steps below to add this extension to your bash builtins at run time.

```bash
#1 Clonning the bash src code

git clone https://git.savannah.gnu.org/git/bash.git

#2 navigate to the bash dir and 

#NOTE: but we need to compite the .c files because bash can not directly call the .c file so we need to turn them into binary modules.

cd bash 
./configure

#./configure? -> because bash uses auto tools running this does several things:
# like detects OS system features, checks compiler behavior,checks libraries,generates platform-specific headers. after this "config.h" is genrated.

#3 then compile the bash

make

#4 navigate to this dir and compile the builtins:

cd bash/examples/loadables
make

#5 use bash builtin manager "enable"

enable -f ./accept accept

#NOTE: -f flag loads a built in from a shared lib file 

#6 run type accept and help accetp for verification

# A quick test:

accept -v fd -r ip 8080

# another terminal:

nc localhost 8080
hello!
## and you can close the connection with control + D

## so we have fd and ip vars:

echo $fd $ip

# we can use another bash builtin named "read" and we can read that into a line.

read -u $fd line 

# and now if we echo the line var we should see the hello! msg:

echo $line -> "hello!"

# if have payed enouph attention the other terminal netcating the localhost is still runnning! how do we close it? 

exec {fd}>&- # this is how we close the conn

# check this path reversal demonestartion:

printf 'GET /../../../../../../etc/passwd HTTP/1.1\r\n\r\n' | nc localhost:8080
```