# byte-insight
Simple byte-wise display of a data stream

## Install
```sh
git clone https://github.com/asmundstavdahl/byte-insight.git
cd byte-insight
make
make install
```

## Usage
```sh
$ echo test | byte-insight 
offset	hex	dec	bin     	name	raw
0	0x74	0d116	01110100	char	t
1	0x65	0d101	01100101	char	e
2	0x73	0d115	01110011	char	s
3	0x74	0d116	01110100	char	t
4	0x0a	0d010	00001010	LF	


```
