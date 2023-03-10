#Compiles and executes 
import os
compile_code = os.system('make')
if compile_code != 0:
    print('Compile time failed!: Suggest looking at code')
else:
    os.system('./main')