package com.collective.experiments;

import gnu.trove.set.TIntSet;
import gnu.trove.set.hash.TIntHashSet;

import java.util.Date;


/**
 * Created by IntelliJ IDEA.
 * User: christoph
 * Date: 30.04.11
 * Time: 13:23
 * To change this template use File | Settings | File Templates.
 */
public class Intersections {
    public static void main(String args[]) {
        TIntSet one = new TIntHashSet(10000000);
        TIntSet two = new TIntHashSet(10000000);
        long t = new Date().getTime();
        for (int i=0;i<10000000;i++) {
            one.add(i);
        }
        System.out.println((new Date().getTime()-t));
        t = new Date().getTime();
        for (int i=0;i<10000000;i++) {
            two.add(i);
        }
        System.out.println((new Date().getTime()-t));
        t = new Date().getTime();
        new TIntHashSet(two).retainAll(one);
        System.out.println((new Date().getTime() - t));

    }

}
