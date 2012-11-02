;@author: Josh Bernitt
;this file defines the genetic algorithm to be used for this project

;this is our test initial population
(setf init_population '((1 2 3 4 4) (2 1 4 5 3)))

;this is our goal for testing
(setf goal '(1 2 3 4 5))

;the genetic algorithm takes in some beginning population and a fitness function
;it then returns the fittest individual
(defun GeneticAlgorithm (population SomeFitnessFunc)
  (FitnessFunc (car population) SomeFitnessFunc) ;generic fitness function operating on 
                                                         ;the more precise one passed as an arg
  (GeneticAlgorithm (cdr population) SomeFitnessFunc)
)

;takes in some organism and determines how fit it is based upon how close to 
;the goal state it is. This is a generic fitness function, and as such it accepts
;a function as a parameter in order to determine the fitness. Much like a wrapper
(defun FitnessFunc (organism SomeFitnessFunc)
  (if (equal organism goal)
     1 ;if all is correct, return 100% 
    (/ (funcall SomeFitnessFunc organism) (length goal))) ;else return the fraction of correct
)

;this is a super simple fitness function that determines fitness based on 
; how many "red" pegs we receive. White pegs are ignored     
(defun SimpleFitnessFunc (organism)
  (let ((l (mapcar 'equal organism goal)) (c 0)) ;sets a list to how many points are equal
    (loop for i in l
	 do (if (equal i T) (setf c (+ 1 c)) nil) ;calculates the number of true's in the list 
    )
    c ;evals to the number of true's
  )
)