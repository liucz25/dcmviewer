import pydicom
import numpy as np
import matplotlib.pyplot as plt
import okWangluoPydicom as tz
from sklearn.decomposition import PCA



file='1.dcm'
ds=pydicom.dcmread(file)
img,wight,hight=tz.get_pixeldata(ds)

img_low=tz.setDicomWinWidthWinCenter(img,80,40,wight,hight)



# plt.imshow(img_arr)
plt.imshow(img_low,cmap=plt.cm.gray)
# plt.imshow(img_arr,cmap=plt.cm.gray)
# plt.show()

pca =PCA(0.999)
pca.fit(img_low)
img_low_pca=pca.transform(img_low)
img_low_inv=pca.inverse_transform(img_low_pca)

plt.imshow(img_low,cmap=plt.cm.gray)
plt.show()