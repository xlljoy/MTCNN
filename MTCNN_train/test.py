import numpy as np
import cv2
import h5py
import sys
caffe_root = '/Users/lixile/caffe/'
sys.path.insert(0, caffe_root + 'python')
import caffe

read_1 = '/Users/lixile/Desktop/xile.jpg'
read_2 = '/Users/lixile/Desktop/aaa.jpg'
img = cv2.imread(read_1)
img_array = []
img_forward = np.array(img, dtype=np.float32)
img_array.append(img)

img = cv2.imread(read_2)

img_forward = np.array(img, dtype=np.float32)
img_array.append(img)

min_face_size = 24


label = np.loadtxt('/Users/lixile/Documents/dataset/celeba/label.txt', int)
landmark = np.loadtxt('/Users/lixile/Documents/dataset/celeba/landmark.txt', float)
regression_box = np.loadtxt('/Users/lixile/Documents/dataset/celeba/regression_box.txt', float)

label = np.transpose([label])
#landmark = np.transpose(landmark)
labels = np.concatenate((label, regression_box, landmark), axis = 1)

img_array = []
for line in open('/Users/lixile/Documents/dataset/celeba/crop_image.txt'):
    #lines = '/Users/lixile/Documents/dataset/celeba/img/' + line.strip()
    img = cv2.imread(line.strip())
    img = cv2.resize(img, (24,24))
    #img = cv2.convertTo(img, cv2.CV_32FC3, 0.0078125,-127.5*0.0078125)
    img = cv2.transpose(img)
    img_forward = np.array(img, dtype=np.float32)
    img_forward = np.transpose(img_forward, (2, 0, 1))
    img_forward = (img_forward - 127.5) * 0.0078125
    img_array.append(img_forward)

a = np.array(img_array, dtype=np.float32)



#f = h5py.File("/Users/lixile/Documents/dataset/celeba/train.hd5", "w")
#f.create_dataset("data", data=a,  compression="gzip", compression_opts=4)
#f.create_dataset("label", data=label,  compression="gzip", compression_opts=4)
#f.close()

with h5py.File('/Users/lixile/Documents/dataset/celeba/train_24.hd5', 'w') as f:
    f['data'] = a
    f['labels'] = labels
    #f['regression'] = regression_box
    #f['landmark'] = landmark
