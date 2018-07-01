# byte-insight
Simple byte-wise display of a data stream with UTF-8 support.

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
offset	hex	dec	bin     	name	raw	utf8
0	0x74	0d116	01110100	ASCII	t	t
1	0x65	0d101	01100101	ASCII	e	e
2	0x73	0d115	01110011	ASCII	s	s
3	0x74	0d116	01110100	ASCII	t	t
4	0x0a	0d010	00001010	LF	
	

$ echo Åsmund | byte-insight
offset	hex	dec	bin     	name	raw	utf8
0	0xc3	0d195	11000011	u-start	�	�
1	0x85	0d133	10000101	u-cont	�	Å
2	0x73	0d115	01110011	ASCII	s	s
3	0x6d	0d109	01101101	ASCII	m	m
4	0x75	0d117	01110101	ASCII	u	u
5	0x6e	0d110	01101110	ASCII	n	n
6	0x64	0d100	01100100	ASCII	d	d
7	0x0a	0d010	00001010	LF	
	

```
