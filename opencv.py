import cv2

import numpy as np

import matplotlib.pyplot as plt

 

live_Camera = cv2.VideoCapture(0)

 

while(live_Camera.isOpened()):

    ret, frame = live_Camera.read()

 

    cv2.imshow("Fire Detection",frame)

 

    if cv2.waitKey(10) == 27 :

        break

 

live_Camera.release()

cv2.destroyAllWindows()
