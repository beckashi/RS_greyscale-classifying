# greyscale classifying #

Our 3Pi+ is expected to use infrared sensors for the purpose of greyscale classifying varying surfaces.

Firstly, we need to collect the return value of infrared sensors on a certain distance of different greyscale surfaces and in the same environment.
When performing the task, we would have the robot move across the surface and connect the robot to the computer, allowing the sensing intensity of the reflection collected by the sensors to be returned to the computer.
This data will help us to identify the specific greyscale of surface that robots are moving on at different times.

Areas of greyscale must be seperated by a distance or limited to some size - what are the limits here? Therefore, you could hypothesise when the greyscale classifying will begin to break, and then make an experiment to measure if this is true.  This is just an example, and it will depend on what you actually implement.  A good way to think about this step of analysis/evaluation, is that if you were designing a product or buying a product, you will need to also know the limits of the performance of the system to make a good decision.  E.g, if I was to buy your greyscale classifying solution, I would want to know how many greyscale classifications can read, but also the limits, when it will go wrong, etc, so I can decide if it will suit my application.   So aim to make this kind of analysis and evaluation the end goal of your work. 

The dataTest.csv is stored under the repo called beckashi/dataStore/.

## Steps:  ##
1. use surfaceIdentify1.0_SensorDetect.ino to produce the sensors data.


2. paste the data to https://github.com/beckashi/dataStore/blob/main/dataTest.csv


3. plotResult.ipynb: https://colab.research.google.com/drive/1Fg0-xJ_PaPvFWkQ5SWlP1DjHU3JsP7bi

4. finish the report: https://www.overleaf.com/project/655f47adc3d609059c955f57

next, should add calibration and filter

## plan:  ##
Week1: discuss about greyscale classifying to work. 

Then, make a clear design about the challenges and make the actual hypothesis of our investigation.

(11.9 before the meeting with supervisor)


From Dr. Paul:

Week 1: write code, take measurements, plot graphs, take to meeting

Week 2: decide what technique to apply to filter out noise, or combine sensors to improve measurement accuracy/precision, implement, test, plot results

Week 3: decide what else is interesting

Week 4: Focus on report

Week 5: finish writing report.
(12.4: finish the whole report)

**Hi,some immportant points from Dr paul's feedback**
-Your proposal could have two distinct elements.
  ...One is to find or locate an IR source in the environment
  ...whilst the other could be about classifying different surfaces by their tone/darkness (greyscale).

  *the robot can detect heat sources
  *he robot can detect candle flames (like a tealight candle) - however I think it is detecting just a narrow band of IR being emitted, not necessarily heat.
  *Therefore, a good source of IR to use is another robot, with it's plastic body shell removed.  Where your proposal has a few different possible tasks, **my recommendation is to quickly select just one to investigate**
  
........................................so this is the proposal he want us to work on **Surface discrimination** ......................................................................
>>> My recommendation here would be to quickly make an implementation of this system and evaluate it, so that you can then decide how it could be improved further.  This improvement will be the actual hypothesis of your investigation.
>>> >>>> We can imagine that filtering some noise on the sensors, or a way to combine all 5 line sensors, would be an improvement.
>>> >>>>
>>> >>>> >>>>you could investigate some simple filters like an exponential moving average, or more statistical methods like inverse-variance weighting
>>> >>>> >>>>our robot should be able to collect many samples quickly enough to apply something like this on every loop().
>>> >>>> >>>>
>>> >>>> >>>>Therefore, you could hypothesise when the greyscale classifying will begin to break, and then make an experiment to measure if this is true.

....................................................................**Line sensor calibration/filtering**............................................................................

>>>You outline measuring the effect of changing the lighting conditions and I can see you have given good thought to the different scenarios to test under
>>>In your report, this means your introduction will probably include "preliminary results", because discussing the measurable impact of lighting would help the reader to understand the nature of the problem you are investigating.
>>>you can then state how you predict an improvement can be made.   Therefore, to produce a more interesting of work, you then want to predict how to make it better, and then evidence whether this was successful or not
>>>Your proposal is about a calibration method for the line sensors, or implementing some kind of filter for the sensors. Using the task of line following is a good and reasonable way to evaluate your system.
>>>An important aspect will be to keep the motion/line follow controller always the same - otherwise we won't know if a change in performance is from your calibration/filtering, or from a change of controller.
>>>
