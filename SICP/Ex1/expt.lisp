(define (expt b n)
	(expt-iter b n 1))

(define (expt-iter b cnt product)
	(if (= cnt 0)
		product
		(expt-iter b (- cnt 1) (* b product))))

(expt 2 4)
