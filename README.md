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
$ echo test | ./byte-insight
offset  hex     dec     bin             name    raw     utf8
0       0x74    116     01110100        ASCII   t       t
1       0x65    101     01100101        ASCII   e       e
2       0x73    115     01110011        ASCII   s       s
3       0x74    116     01110100        ASCII   t       t
4       0x0a    10      00001010        LF


$ echo Åsmund | ./byte-insight ohun
offset  hex     utf8    name
0       0xc3            u-start
1       0x85    Å       u-cont
2       0x73    s       ASCII
3       0x6d    m       ASCII
4       0x75    u       ASCII
5       0x6e    n       ASCII
6       0x64    d       ASCII
7       0x0a
        LF
$ ./byte-insight --help
Usage: ./byte-insight [ohdbnru]*
        o - offset
        h - hex
        d - dec
        b - bin
        n - name
        r - raw
        u - utf8
```
