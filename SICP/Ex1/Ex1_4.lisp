;calculate the sum of a and the absolute value of b
(define (a-plus-abs-b a b)
((if (> b 0) + -) a b))