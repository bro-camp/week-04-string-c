# Run script for C project
import os

# USER DEFINED VALUES
build_file_name = 'hello-world.exe'

# --------------------------------------------------------------------

cwd = os.getcwd()
# Windows path back slash to forward slash
cwd = cwd.replace('\\', '/')

build_dir = cwd + '/' + 'build'
build_file_path = build_dir + '/' + build_file_name

# print(build_file_path) # For debugging
os.system(build_file_path)
