import numpy as np
from numpy.linalg import eigvals
def run_experiment(niter=100):
	K = 100
	results = []
	for _ in xrange(niter):
		mat = np.random.randn(K, K)
		max_eigenvalue = np.abs(eigvals(mat)).max()
		results.append(max_eigenvalue)
	return results

some_results = run_experiment()
print 'Largest one we saw: %s' % np.max(some_results)






from my_functions import g
	def f(x, y):
		return g(x + y)
	def main():
		x = 6
		y = 7.5
		result = x + y

if __name__ == '__main__':
	main()

def main():
	x = 6
	y = 7.5
	result = x + y

print __name__
if __name__ == '__main__':
	main()
	print result