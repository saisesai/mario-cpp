import os
import shutil
import sys

sys.path.append(r"./script")

from Util import *

def main():
	print("start clean:")
	print("windows_x86_64:")
	if os.path.exists("./bin"):
		shutil.rmtree("./bin")
		print("success!")
	else:
		print("no file should clean!")
	print("start copy:")
	os.mkdir("./bin")

	target_path = './bin'

	source_path = "./out/build/x86-Debug/mario.exe"
	print("copy:"+source_path)
	shutil.copy(source_path, target_path)

	source_path = "./out/build/x86-Debug/glfw3.dll"
	print("copy:"+source_path)
	shutil.copy(source_path, target_path)

	source_path = "./out/build/x86-Debug/glew32d.dll"
	print("copy:"+source_path)
	shutil.copy(source_path, target_path)

	source_path = "./out/build/x86-Debug/engine.dll"
	print("copy:"+source_path)
	shutil.copy(source_path, target_path)

	print("copy:./assets")
	copytree("./out/build/x86-Debug/assets", "./bin/assets")
	print("success!")

	print("create:./bin/log/")
	os.mkdir("./bin/log/")
	print("success!")

	print("create:./bin/log/log.txt")
	open("./bin/log/engine.log", "a").close()
	print("success!")

	print("create zip file:")
	zip_file("./bin", "./", "windows_x86_64.zip")
	print("success!")

	print("move zip file")
	shutil.move("./windows_x86_64.zip", "./bin/")
	print("success!")

if __name__ == '__main__':
	main()