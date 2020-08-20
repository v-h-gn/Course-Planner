
# BCOE Course Planner
 > Authors: [Vahagn Tovmasian](https://github.com/Varhagna) [Selma Kondoker](https://github.com/skondoker)

## Project Description
 
 Our project will be a course planning software for UCR students within the College of Engineering
 In our experience, showing prospective students the course plan and talking to them about how useful, as well as using it ourselves has shown us the benefits of a good course plan. We want to extend that tool but generate a custom course plan depending on conditions inputted by the user.
 
 This project will be completed in C++, we have yet to decide what tools in specific we will use but will expect to know once we get a better grasp of the exact design details we want to incorporate. We want to be able to generate a PDF however for the initial release this will not be accomplished, however. We also intend to be able to parse through the catalog for a specific inputted major within BCOE and get the requirements they need & course prereqs and similar requirements.

  * Abstract factory creational pattern to create families of classes from the course catalog.
  * Composite structural pattern to create our class tree and indicate hierarchies with pre-requisites.
  * Observer behavioral pattern to handle and update changes made to the course schedule.
 
 The input output of our project will be any student specific information such as credits completed, courses taken and passed, expected or planned graduation date, which will create a customized course plan they can follow as they progress through their degree.
 
## Class Diagram

   https://docs.google.com/document/d/1O9iIQU9e-WxCcY_7MSfIGi9Epqv_0VS6sOeGDtp6o5U/edit?usp=sharing
   
   Our diagram illustrates a Client which uses the Abstract Factory Pattern to utilise a PDF Parser to read through and construct different Components which can then be constructed into a heirarchical tree. The tree is also being tracked by an Observer Class which gets passed user input from the Client
 
 > ## Phase III
 > You will need to schedule two check-in's with the TA (during lab hours or office hours) where your entire group will meet with them and discuss:
 > * What you have each done up to this point
 > * What you plan to do until the next meeting (or until the final demo)
 > * If there is anything that is getting in your way
 
 > You may notice that this is effectively a "standup" meeting. We suggest that as a team you have a daily (or every other day) standup, but this will be a bit more formal with the TA. 
 
 > **Your meetings cannot be in the same week of the session so plan ahead**

 > ## Final deliverable
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
