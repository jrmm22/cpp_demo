
### Text encrypt:

#### How to build + run:

```
$ g++ encrypt.cpp -o encrypter

$ ./encrypter
```

#### Sample run:

Generate the key, requests a key.


In this example, the message is 'hello world' and key is 'hello'
```
Generated key
nwlrb
What message?
hello world
What key? ('GEN' to use the generated one)
hello
Encrypted message: 
pjxxd etdxs
```

In this example, the message is 'pixie dust' and key is 'pixie'
```
Generated key
nwlrb
What message?
pixie dust
What key? ('GEN' to use the generated one)
pixie
Encrypted message: 
frvrj tdqc
```

In this example, the message is 'pixie dust'. The key to use is 'GEN' so the code will use
'nwlrb', which was randomly generated.
```
Generated key
nwlrb
What message?
pixie dust
What key? ('GEN' to use the generated one)
GEN
Using generated key nwlrb
Encrypted message:
dfjag rrel
```

In this failure example, the key is less than 5 characters long, so the encryption is not done.
```
Generated key
nwlrb
What message?
hello world
What key? ('GEN' to use the generated one)
123
Key needs to be 5 characters long
```

In this failure example, the message includes an upper case letter, so it is rejected.
```
$ ./a.out 
Generated key
nwlrb
What message?
Hello world
What key? ('GEN' to use the generated one)
Hello
Message can only contain lowercase characters.
Failed encrypting message 
```
