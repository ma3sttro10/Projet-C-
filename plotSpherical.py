#!/bin/python3

import sys
import numpy                as     np
import matplotlib.pyplot    as     plt
from   matplotlib           import cm
from   mpl_toolkits.mplot3d import Axes3D

if len(sys.argv)<2:
  print("Specify the maximum degree to plot")
  sys.exit()

lmax   = int(sys.argv[1])
depth  = 1
# Specify where the files are located, leave empty if files
# are in the same directory
resdir = ""

def plotHarmonic(l,m,ax):
  fileName = resdir + "y_" + str(l) + "_" + str(m) + ".txt"
  data   = np.loadtxt(fileName)
  maxd   = np.max(np.max(np.abs(data)))
  ntheta = data.shape[0]
  nphi   = data.shape[1]
  theta  = np.linspace(0,np.pi,ntheta)
  phi    = np.linspace(0,2*np.pi,nphi)
  tt,pp  = np.meshgrid(theta,phi,indexing='ij')
  x      = (1+depth*data/maxd)*np.sin(tt)*np.cos(pp)
  y      = (1+depth*data/maxd)*np.sin(tt)*np.sin(pp)
  z      = (1+depth*data/maxd)*np.cos(tt)
  ax.plot_surface(x,y,z,rcount=ntheta/2,ccount=nphi/2,facecolors=cm.winter(data/(np.abs(data))))
  ax.grid(False)
  ax.set_xticks([])
  ax.set_yticks([])
  ax.set_zticks([])
  ax.set_title("Y_{:d}^{:d}".format(l,m))

fig = plt.figure(figsize=(3*(2*lmax+1),3*(lmax+1)))
for l in range(lmax+1):
  for m in range(-l,l+1):
    print("Generating subplot for harmonic ({:3d},{:3d})".format(l,m),end='\r')
    ax = fig.add_subplot(lmax+1,2*lmax+1,1+ (2*lmax+1)*l + (lmax+m),projection='3d',proj_type='ortho')
    plotHarmonic(l,m,ax)
print()
print("Finalizing png image")
plt.savefig(resdir+"harmonics.png")

