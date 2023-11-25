SUBDIRS = tools
check_LTLIBRARIES = libgtest.la
libgtest_la_SOURCES = ../googletest/googletest/src/gtest-all.cc
libgtest_la_CPPFLAGS = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest
libgtest_la_LDFLAGS = -pthread

bin_PROGRAMS = test bench
noinst_PROGRAMS = bench

test_SOURCES = test.cpp
test_CPPFLAGS = -I ${top_srcdir}/googletest/googletest/include/
test_LDADD = libgtest.la
test_LDFLAGS = -pthread

bench_SOURCES = bench.cpp 
bench_LDFLAGS = -lbenchmark -pthread

TESTS = test
