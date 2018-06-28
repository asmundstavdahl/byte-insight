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
head -c1 /dev/urand | byte-insight
```
