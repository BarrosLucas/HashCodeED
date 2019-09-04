# -*- coding: utf-8 -*-
"""
Created on Tue Sep  3 23:25:44 2019

@author: lucas
"""

import numpy as np
import matplotlib.pyplot as plt

legendas = ['1ª FH','2ª FH','3ª FH','4ª FH','5ª FH','6ª FH','7ª FH']
desvios = [46.407289,57.296364,44.296974,77.448266,57.296364,57.296364,2.480069]

plt.bar(legendas,desvios,color="red")
plt.xticks(legendas)
plt.xlabel('Função Hash')
plt.ylabel('Desvio Padrão')
plt.title('Desvio padrão por função hash')

plt.show()