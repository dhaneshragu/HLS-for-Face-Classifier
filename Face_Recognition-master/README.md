# Description - Face_Recognition
Face Detection and Recognition on some famous personalities

## 1. Dataset acquisition
- Train Data

  Collected a set of 60 images of famous celebrities of India (namely Deepika Padukone, Ayushmaan Khurrana, Kriti Sannon, Sushant Singh Rajput, Narendra Modi, Carryminati) for the training set.
-  Validation Data 


   Collected 18 images of the same celebrities for the validation set.

## 2. Detection of Faces
Using ```dlib cnn face detector``` to find the faces in image, crop and store them in separate folders sorted according to individual person.
Download 'mmod_human_face_detector' to use as 'dlib cnn face detector'
```
! wget http://dlib.net/files/mmod_human_face_detector.dat.bz2 
! bzip2 -dk mmod_human_face_detector.dat.bz2
```
The directory structure looks like this:
```
Directory structure :
|Images /
|  |-- (60 images)
|Images_crop /
|  |--ayushmaan/
|     |--(10 images)
|  |--carry/ 
|     |--(10 images)
|  |--deep/ 
|         |--(10 imgaes)
|  |-- sush/ (10 images)
|  |--kriti / (10 images) 
|  |--modi / (10 images)
|Images_test / 
|  |-- .. / (18 images)
|Images_test_crop / 
|  |--ayushmaan / (3 images)
|  |--carry / (3 images)
|  |--deep / (3 imgaes)
|  |--kriti / (3 images)
|  |--modi / (3 images)
|  |--sush / (3 images) 
|Upload_your_images /
|  |--Here you can put your own images to test the model
|Your_predictions /
|  |--The result
|Face_Recognition.ipynb
|mmod_human_face_detector.dat
```
## 3. Download the model weights
As vgg-face weights are not available as ```.h5``` file to download,from this [article](https://sefiks.com/2018/08/06/deep-face-recognition-with-keras/)
  
  Download Vgg-face weights from google drive with
```! gdown https://drive.google.com/uc?id=1CPSeum3HpopfomUEK1gybeuIVoeJT_Eo```
Define vgg-face model architecture in tensorflow-keras and load weights.

## 4. Train Softmax regressor for 6 person classification from embeddings.
Prepare train data and test data from the embeddings and feed into a simple softmax regressor with 3 layers containing first layer with 100 units and tanh activation function , second layer with 10 units and tanh activation function and third layer with 6 units for each person with softmax activation.
- Predictions
For an image(may contain multiple faces) extract each face,get embeddings,get prediction from classifier network,make bounding box around face and write person name.


## 5. Sample Images of Face Recognised Images

![sush_1](https://user-images.githubusercontent.com/45651909/89097462-b62f6480-d3fc-11ea-971c-1deb9018b7eb.jpg)
![modi_2](https://user-images.githubusercontent.com/45651909/89097466-ba5b8200-d3fc-11ea-8823-5c9081e8f7e5.jpg)
![deep_1](https://user-images.githubusercontent.com/45651909/89097470-bc254580-d3fc-11ea-815d-b512c2b2a3f8.jpg)
![ayushmaan_2](https://user-images.githubusercontent.com/45651909/89097472-bdef0900-d3fc-11ea-905d-799b0a599cbb.jpg)
![deepika](https://user-images.githubusercontent.com/45651909/89098748-ddd7fa00-d407-11ea-962e-701b9c979e05.jpg)
![DwnavjPUYAAqEh2](https://user-images.githubusercontent.com/45651909/89098751-e2041780-d407-11ea-8c3b-64b0edcd2df7.jpg)
![when_sushant_singh_rajput_revealed_similarities_between_him_kriti_sanon_to_be_the_reason_of_their_friendship](https://user-images.githubusercontent.com/45651909/89098753-e5979e80-d407-11ea-90f8-610d7b47b6d0.jpeg)

Good to go with your model. ✔✌
