import os
import sys

sys.path.append(r"./script")

from Util import *

def main():
	print("start clean:")
	print("x86-Debug:")
	if os.path.exists("./out/build/x86-Debug/assets"):
		shutil.rmtree("./out/build/x86-Debug/assets")
		print("success!")
	else:
		print("no file should clean!")
	print("x86-Release:")
	if os.path.exists("./out/build/x86-Release/assets"):
		shutil.rmtree("./out/build/x86-Release/assets")
		print("success!")
	else:
		print("no file should clean!")

	print("start copy:")
	copytree("./assets", "./out/build/x86-Debug/assets")
	copytree("./assets", "./out/build/x86-Release/assets")
	print("success!")

	

if __name__ == '__main__':
	main()