#!/usr/bin/env ruby
require 'spec_helper'

def createDListNode(value, prev=nil, nextNode=nil)
  obj_ptr2 = FFI::MemoryPointer.new :pointer
  obj_ptr1 = FOO.createElem(value, prev, nextNode)
  FOO::DList.new(obj_ptr1)
end


describe "unit tests for DList" do
  before(:each) do
  end

  #it "should really foo" do
    # This function takes a pointer-to-uint32 out-param
    #out = FFI::MemoryPointer.new :uint32

    #res = FOO.foo_count_letters(1)

    # Read back the pointers to Ruby data types, then use rspec's verification functions
    #out.get_uint32(0).should == 5
    #res.should == 1

   # 2.should == 2
  #end

  it "Create elem works" do
#    obj_ptr2 = FFI::MemoryPointer.new :pointer
#    obj_ptr1 = FOO.createElemNo(2)
#    obj1 = FOO::DList.new(obj_ptr1) # wrap ruby object around C pointer
    obj1 = createDListNode(2)
    obj1[:next] = nil
    obj1[:next].should == nil
    obj1[:x].should == 2
  end

  it "shuld work like a linked list" do
    obj1 = createDListNode(1)
    obj2 = createDListNode(2, obj2)
    obj1[:next] = obj2
    obj2_value = FOO::DList.new(obj1[:next])
    obj2_value[:x].should == 2

    prev = FOO::DList.new(obj2[:prev])
    prev[:x].should == 1


  end

end