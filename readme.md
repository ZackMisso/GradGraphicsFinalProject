Instructions on Running ::

We have a few different Views set up that you can watch our fracture
simulation work. However be warned, some of them take a while (2 minutes)
to get going.

Choose the View that you want to see by going into:
  views/viewController.cpp
and uncommenting out the view you want to see in the constructor

Press b to switch between seeing springs and not springs

Finalized Views:
  FRACTURE_ONE
  FRACTURE_TWO
  FRACTURE_THREE
  FRACTURE_FOUR
  FRACTURE_FIVE

Cool Fails: (caused by us picking bad constraints (spring coeff and dampening))
  AWESOME_FAIL
  FRACTURE_FAIL

NOTE :: make sure only one switchToView call is uncommented at a time...
we did not test that the deconstructors worked for all views...
