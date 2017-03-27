(define (even? n)
	(= (remainder n 2) 0))

;(* 2 n) ; there is no default arithmetic multiplication '*' here 
(define (double n)
	(+ n n))
	
(define (halve n)
		(/ n 2))

; invariant quantity acc + a*b
(define (* a b)
	(define (iter acc a b)
		(cond ((= b 0) acc)
			((even? b) (iter acc (double a) (halve b)))
			(else (iter (+ acc a) a (- b 1)))))
(iter 0 a b))
