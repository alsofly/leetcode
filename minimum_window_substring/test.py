#!/usr/bin/python3

import sys
import subprocess

TEST = [
   {
      's' : 'aaabdabcefaecbef',
      't' : 'abc',
   },
   {
      's' : 'bccabccbbaaacbcbc',
      't' : 'aac',
   },
   {
      's' : 'acbba',
      't' : 'aab',
   },
]

# Run command line 
def shell(cmdList):
   print("Calling shell({0})".format(cmdList))
   process = subprocess.Popen(
         cmdList,
         stdout=subprocess.PIPE)
   stdout, stderr = process.communicate()

   if ( stderr ): return stderr
   else: return stdout



def main():
   for case in TEST:
      output = shell([
         './a.out',
         case['s'],
         case['t'],
      ])
      print(output)






if __name__ == "__main__":
   main()
