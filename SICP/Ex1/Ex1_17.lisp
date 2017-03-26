(define (even? n)
	(= (remainder n 2) 0))

(define (double n)
	(+ n n)
	;(* 2 n) ; there is no default arithmetic multiplication '*' here 
	)

(define (halve n)
		(/ n 2)
	)

(define (* a b)
	(cond ((= b 0) 0)
	((even? b) (double (* a (halve b))))
	(else (+ a (* a (- b 1))))))

; (* 2 4)
