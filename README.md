# base64
Easy base64 encoder/decoder

## using:
```C++
std::string word = "Hello world!";
std::string b64word = base64::base64_encode(word);     //SGVsbG8gd29ybGQh
std::string db64word = base64::base64_decode(b64word); //Hello world!
```
