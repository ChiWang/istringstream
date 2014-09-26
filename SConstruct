'''
 *  $Id: SConstruct, 2014-03-07 15:07:43 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 23/09/2013
 *----------------------------------------------------------
 *  Setup install method for istringstream
 *  1. if you want to install the whole istringstream, execute
 *      scons
 *      at current directory
 *  2. if you want to re-install some certain packages:
 *      scons package=package_1,package_2,package_3
 *  3. installation layout
 *      prefix/bin
 *      prefix/include
 *      prefix/lib
 *      prefix/share
 *----------------------------------------------------------
'''

import os

# functions
#--------------------------------------------------------------------
def checkSysEnv(var):
    if not os.environ.has_key(var):
        print "\tERROR:\tNot has environment variable: %s" % var
        Exit(1)

def useCLHEP(aEnv):
    aEnv.ParseConfig("clhep-config --include --libs")

def useRoot(aEnv):
    checkSysEnv('ROOTSYS')
    aEnv.ParseConfig("root-config --cflags --libs")
    #aEnv.Append(LIBS=['RooFitCore','RooFit'])

def useGeant4(aEnv):
    checkSysEnv('G4INSTALL')
    g4sys=os.environ['G4INSTALL']
    aEnv.PrependENVPath('PATH', g4sys+'/../../../bin')
    aEnv.ParseConfig("geant4-config --cflags --libs")

def useBoostPython(aEnv):
    aEnv.ParseConfig("python-config --include --libs")
    aEnv.Append(LIBS=['boost_python'])
    #aEnv.Append(LIBS=['boost_program_options-mt'])

def useOpenMP(aEnv):
    aEnv.MergeFlags('-fopenmp')

# set basical environment
#--------------------------------------------------------------------
envBase = Environment(ENV = os.environ)

# set general variables
#--------------------------------------------------------------------
project="istringstream"    # or you can set an ABBREVIATION
prefix=project+'Install'
'''
if os.environ.has_key(project+'SYS'):
    prefix=os.environ[project+'SYS']
else:
    UsrPrefix=raw_input('Where to install istringstream (press Enter to use default "%s"): ' %prefix)
    UsrPrefix=UsrPrefix.strip()
    if UsrPrefix:
        prefix=UsrPrefix
'''
prefix=os.path.abspath(prefix)
print "install istringstream into: ", prefix

# mode tag
#--------------------------------------------------------------------
if int(ARGUMENTS.get('debug',1)):
    envBase.Append(CCFLAGS = ['-g','-DMy_Debug'])

# invoke *.scons file of top-1 packages
#--------------------------------------------------------------------
pkgList='src'
pkgList=ARGUMENTS.get('package',pkgList)
pkgList=pkgList.split(',')
subScript=[]
for key in pkgList:
    subScript=subScript+[key+'/'+key+'.scons']

SConscript(subScript,exports=['prefix','project','envBase','useRoot','useGeant4','useBoostPython','useCLHEP','useOpenMP'])
#SConscript(subScript,exports=['prefix','project','envBase'],variant_dir='Scons',duplicate=0)

