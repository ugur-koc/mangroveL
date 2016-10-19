from __future__ import print_function
from six.moves import xrange
import six.moves.cPickle as pickle

import gzip
import os
import nltk, re

import numpy
import theano


def prepare_data(seqs, labels, maxlen=None):
    lengths = [len(s) for s in seqs]

    if maxlen is not None:
        new_seqs = []
        new_labels = []
        new_lengths = []
        for l, s, y in zip(lengths, seqs, labels):
            if l < maxlen:
                new_seqs.append(s)
                new_labels.append(y)
                new_lengths.append(l)
        lengths = new_lengths
        labels = new_labels
        seqs = new_seqs

        if len(lengths) < 1:
            return None, None, None

    n_samples = len(seqs)
    maxlen = numpy.max(lengths)

    x = numpy.zeros((maxlen, n_samples)).astype('int64')
    x_mask = numpy.zeros((maxlen, n_samples)).astype(theano.config.floatX)
    for idx, s in enumerate(seqs):
        x[:lengths[idx], idx] = s
        x_mask[:lengths[idx], idx] = 1.

    return x, x_mask, labels


def load_data(path='imdb.pkl', n_words=100000, valid_portion=0.1, maxlen=None, sort_by_len=True):
    file_content = open('codeData/bad.c', 'r')
    #file_content2 = open("codeData/bad.c").read()
    #tokens = nltk.word_tokenize(file_content2)
    dict={'auto':10000, 'break':10001, 'case':10002, 'char':10003, 'const':10004, 'continue':10005, 'default':10006, 'do':10007, 'double':10008, 'else':10009, 'enum':10010, 'extern':10011, 'float':10012, 'for':10013, 'goto':10014, 'if':10015, 'int':10016, 'long':10017, 'register':10018, 'return':10019, 'short':10020, 'signed':10021, 'sizeof':10022, 'static':10023, 'struct':10024, 'switch':10025, 'typedef':10026, 'union':10027, 'unsigned':10028, 'void':10029, 'volatile':10030, 'while':10031, 'abstract':10032, 'array':10033, 'bool':10034, 'catch':10035, 'class':10036, 'const_cast':10037, 'decltype':10038, 'delegate':10039, 'delete':10040, 'deprecated':10041, 'dllexport':10042, 'dllimport':10043, 'dynamic_cast':10044, 'event':10045, 'explicit':10046, 'false':10047, 'finally':10048, 'friend':10049, 'friend_as':10050, 'gcnew':10051, 'generic':10052, 'initonly':10053, 'inline':10054, 'interface':10055, 'interior_ptr':10056, 'literal':10057, 'mutable':10058, 'naked':10059, 'namespace':10060, 'new':10061, 'noinline':10062, 'noreturn':10063, 'nothrow':10064, 'novtable':10065, 'nullptr':10066, 'operator':10067, 'private':10068, 'property':10069, 'protected':10070, 'public':10071, 'ref':10072, 'register':10073, 'reinterpret_cast':10074, 'safecast':10075, 'sealed':10076, 'selectany':10077, 'static_assert':10078, 'static_cast':10079, 'template':10080, 'this':10081, 'thread':10082, 'throw':10083, 'true':10084, 'try':10085, 'typedef':10086, 'typeid':10087, 'typeid':10088, 'typename':10089, 'union':10090, 'using':10091, 'uuid':10092, 'value':10093, 'virtual':10094, '++':10095, '+':10096, '--':10097, '-':10098, '==':10099, '=':10100, '>>':10101, '>':10102, '<<':10103, '<':10104, '<=':10105, '>=':10106, '!=':10107, '!':10108, '"':10109, '#':10110, 'STRING':10111, ';':10112, '[':10113, ']':10114, '{':10115, '}':10116, '(':10117, ')':10118, '*':10119, '&':10120, '|':10121, '||':10122, '^':10123, '~':10124, '?':10125, '%':10126, '/':10127, 'N':10128}
    counter=10000
    #for token in tokens:
    #    if token not in dict:
    #        dict[token] = counter
    #        counter+=1
    samples = []
    labels = []
    for line in file_content:
        smpl = []
        prog=line
        if 'badpositive' in line:
            labels.append(0)
            prog = re.sub(' badpositive','', line)
        else:
            labels.append(1)
            prog = re.sub(' goodpositive','', line)
        tokens = nltk.word_tokenize(prog)
        for token in tokens:
            if token in dict:
                smpl.append(dict[token])
            else:
                smpl.append(999999)
        samples.append(smpl)
    
    train_set = (samples, labels)
    test_set = list(train_set)
    if maxlen:
        new_train_set_x = []
        new_train_set_y = []
        for x, y in zip(train_set[0], train_set[1]):
            if len(x) < maxlen:
                new_train_set_x.append(x)
                new_train_set_y.append(y)
        train_set = (new_train_set_x, new_train_set_y)
        del new_train_set_x, new_train_set_y

    # split training set into validation set
    train_set_x, train_set_y = train_set
    n_samples = len(train_set_x)
    sidx = numpy.random.permutation(n_samples)
    n_train = int(numpy.round(n_samples * (1. - valid_portion)))
    valid_set_x = [train_set_x[s] for s in sidx[n_train:]]
    valid_set_y = [train_set_y[s] for s in sidx[n_train:]]
    train_set_x = [train_set_x[s] for s in sidx[:n_train]]
    train_set_y = [train_set_y[s] for s in sidx[:n_train]]

    train_set = (train_set_x, train_set_y)
    valid_set = (valid_set_x, valid_set_y)

    def remove_unk(x):
        return [[1 if w >= n_words else w for w in sen] for sen in x]

    test_set_x, test_set_y = test_set
    valid_set_x, valid_set_y = valid_set
    train_set_x, train_set_y = train_set

    train_set_x = remove_unk(train_set_x)
    valid_set_x = remove_unk(valid_set_x)
    test_set_x = remove_unk(test_set_x)

    def len_argsort(seq):
        return sorted(range(len(seq)), key=lambda x: len(seq[x]))

    if sort_by_len:
        sorted_index = len_argsort(test_set_x)
        test_set_x = [test_set_x[i] for i in sorted_index]
        test_set_y = [test_set_y[i] for i in sorted_index]

        sorted_index = len_argsort(valid_set_x)
        valid_set_x = [valid_set_x[i] for i in sorted_index]
        valid_set_y = [valid_set_y[i] for i in sorted_index]

        sorted_index = len_argsort(train_set_x)
        train_set_x = [train_set_x[i] for i in sorted_index]
        train_set_y = [train_set_y[i] for i in sorted_index]

    train = (train_set_x, train_set_y)
    valid = (valid_set_x, valid_set_y)
    test = (test_set_x, test_set_y)

    return train, valid, test
