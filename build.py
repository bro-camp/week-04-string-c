# Build script for C project
import os

# USER DEFINED VALUES
build_file_name = 'hello-world.exe'

src_file_list = [
  "main.c",
  "lib/str.c",
]

# --------------------------------------------------------------------

cwd = os.getcwd()
# Windows path back slash to forward slash
cwd = cwd.replace('\\', '/')

src_dir = cwd + '/' + 'src'
include_dir = cwd + '/' + 'include'
build_dir = cwd + '/' + 'build'
build_file_path = build_dir + '/' + build_file_name

src_file_list_string = ''
for i in src_file_list:
  src_file_list_string += src_dir + '/' + i + ' '

# BUILD COMMAND
build_command = 'gcc -o ' + build_file_path + ' -I ' + include_dir + ' ' + src_file_list_string

if not os.path.exists(build_dir):
  os.mkdir(build_dir)

# print(build_command) # For debugging
os.system(build_command)
