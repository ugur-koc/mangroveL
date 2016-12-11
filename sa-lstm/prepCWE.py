#!/usr/bin python

import cPickle, re, os, string, random, glob
from os.path import isfile, join

def get_immediate_subdirectories(a_dir):
	return [name for name in os.listdir(a_dir) if os.path.isdir(os.path.join(a_dir, name))]

def obfuscate(sample):
	randStr=''.join(random.choice(string.ascii_lowercase) for _ in xrange(3))
	sample = re.sub('\s+', ' ', sample) # remove multi spaces
	sample = re.sub('good', randStr, sample) #remove the word good 
	sample = re.sub('bad', randStr, sample) #remove the word bad
	sample = re.sub('/\*[^;/]* \*/', '', sample) #remove most of the comments old pattern /\*[\w*:,\(\)-*\d\s_]* \*/
	sample = re.sub('\"[\w+,\(\)\s]+\"', '" STRING "', sample) #unify print out strings
	return sample.strip()

def tokenize(sample):
	helpDict={'\"':' " ', '\(':' ( ', '\)': ' ) ','\[':' [ ','\]': ' ] ','\{': ' { ', '\'':' \' ', ';':' ; ', '==':' == ', '<':' < ', '>':' > ', 
	'!':' ! ', '\+\+':' ++ ', '--':' -- ', '\+': ' + ', '-':' - ', '\#':' # ', '\*':' * ', ',':' , ', '\!=':' != ', '&':' & ', '=':' = '} # '':'  '
	for key in helpDict:
		sample = re.sub(key, helpDict[key], sample)
	sample = re.sub('=\s=','==', sample)
	sample = re.sub('>\s>','>>', sample)
	sample = re.sub('<\s<','<<', sample)
	sample = re.sub('/\s\*','/*', sample)
	sample = re.sub('\*\s/','*/', sample)
	sample = re.sub(' \d+ ',' N ', sample)
	return sample.strip()

def processSample(cweNumber, sampleClass, omitStr, lines, warningLine):
	macroPattern = re.compile("#(if.*def|endif)")
	sample=''
	isSampleLine=False
	counter=1
	sampleFirstLine=counter
	for line in lines: 
		if '/* '+omitStr+' */' in line:
			break
		elif omitStr in line:
			isSampleLine = True
			sampleFirstLine = counter+1
		elif isSampleLine and not macroPattern.match(line):
			sample+=line.rstrip()+' '
		if counter+1==warningLine:
			sample+='WARNINGLINE '
		counter+=1
	if isSampleLine and sample is not '' and counter > warningLine and sampleFirstLine < warningLine: 
		print obfuscate(tokenize(sample)) + ' ' + cweNumber + ' ' + sampleClass + 'positive'

def processFile(fileName, warningLine):
	cweNumber=fileName[fileName.rfind('/')+1::]
	cweNumber=cweNumber[0:cweNumber.index('_')]
	with open(fileName) as file: lines = file.readlines()
	processSample(cweNumber, 'bad', 'OMITBAD', lines, warningLine)
	processSample(cweNumber, 'good', 'OMITGOOD', lines, warningLine)

if __name__ == '__main__':
	pattern = re.compile("CWE\d{2,3}.*\.(c|cpp)")
	julietDir = '/Users/ukoc/juliet/testcases/'
	CWEs = 'CWE134_Uncontrolled_Format_String/s0*/'
	with open('codeData/CWE134.txt') as file: lines = file.readlines()
	for line in lines:
		(fileName,lineNumber,columnNumber,desc)=line.split(":")
		for filepath in glob.glob(julietDir+CWEs+fileName):
			processFile(filepath, int(lineNumber))