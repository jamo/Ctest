require 'pp'
require 'rspec'
require 'ffi'

#gcc -pie -rdynamic -o foo foo.c


require_relative '../bar.rb'
# This module is your bridge from Ruby to C and back

module FOO
  extend FFI::Library

  # Use an absolute path to the executable under test, otherwise ffi will search LD_LIBRARY_PATH.
  ffi_lib File.absolute_path(File.join(File.dirname(__FILE__), "..", "l"))
#  ffi_lib File.absolute_path(File.join(File.dirname(__FILE__), "l"))

  # Function signatures for each function to be tested
  #attach_function :foo_count_letters, [:string, :pointer], :int
  #attach_function :foo_count_letters, [:int], :int
  attach_function :printElementsD, [:pointer], :int
  attach_function :createElem, [:int, :pointer, :pointer], :pointer
  attach_function :createElemNo, [:int], :pointer
  attach_function :insertElementD, [:pointer, :pointer, :int], :pointer

  class DList < FFI::Struct
    layout :x, :int,
        :next, :pointer,
        :prev, :pointer
  end

end

