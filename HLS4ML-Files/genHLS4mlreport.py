import os
import json
import numpy as np
from sklearn.model_selection import train_test_split
import tensorflow.keras as keras
import keras
import matplotlib.pyplot as plt
import random
import math
import hls4ml


os.environ['PATH']='/opt/Xilinx/Vivado/2018.2/bin:' + os.environ['PATH']
keras_model = keras.models.load_model("face_classifier_model.h5")


config = hls4ml.utils.config_from_keras_model(keras_model, granularity='model')
hls_model = hls4ml.converters.convert_from_keras_model
(
     keras_model, hls_config=config, output_dir='/hls4ml_prj', part='xcvu190-flgb2104-1-i'
 )

hls_model.build(csim=False)