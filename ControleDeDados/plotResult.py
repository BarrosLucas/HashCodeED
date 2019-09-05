# -*- coding: utf-8 -*-
"""
Created on Tue Sep  3 23:25:44 2019

@author: lucas
"""

import numpy as np
import matplotlib.pyplot as plt

legendas = ['1ª FH','2ª FH','3ª FH','4ª FH','5ª FH','6ª FH']
desvios = [507,485,361,1698,437,2582]

plt.bar(legendas,desvios,color="red")
plt.xticks(legendas)
plt.xlabel('Função Hash')
plt.ylabel('Tempo (ms)')
plt.title('Tempo na busca pelas palavras no dicionário')

plt.show()