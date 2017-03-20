if NOT DEFINED TARGET_ARCH (
call "D:\Program Files (x86)\IntelSWTools\compilers_and_libraries_2017.2.187\windows\bin\compilervars_arch.bat" intel64 vs2015
call "D:\Program Files (x86)\IntelSWTools\compilers_and_libraries_2017.2.187\windows\mkl\bin\mklvars.bat" intel64
)
python setup.py build
Set MKL_VERBOSE = 1
cp ./build/lib.win-amd64-3.6/* ./ && python Test.py
pause
