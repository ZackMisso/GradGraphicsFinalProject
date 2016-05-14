#Instructions on Running

We have a few different Views set up that you can watch our fracture
simulation work. However be warned, some of them take a while (2 minutes)
to get going.

Choose the default View by going into views/viewController.h
and setting the default argument of `initialize(ViewID)` to be the desired View.

You may also specify the view by passing the view's ID to the program. The view IDs are specified in `views/viewController.h`

Example: `./fracture 14`

Press b to switch between seeing springs and not springs. Blue lines represent springs, and white lines represent broken springs.

Finalized Views:

- FRACTURE_ONE = 14
- FRACTURE_TWO = 15
- FRACTURE_THREE = 16
- FRACTURE_FOUR = 17
- FRACTURE_FIVE = 18
- FRACTURE_THREE3D = 19

Cool Fails: (caused by us picking bad constraints (spring coeff and dampening))

- AWESOME_FAIL = 20
- FRACTURE_FAIL = 21

**NOTE** :: make sure only one switchToView call is uncommented at a time...
we did not test that the deconstructors worked for all views...