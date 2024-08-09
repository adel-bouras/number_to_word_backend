#include <iostream>
#include <math.h>
int main() {
        std::string words = "" ;
        int step = 1000000000;
            int num =0;

            std::cout<<"please enter your number \n";
            std::cin>>num;
            std::cout<<"you number is: \n";




        while(step != 0){

                if(num / step != 0){
                    if(step == 10 || step == 10000 || step == 10000000){



                        int ten = num / step;
                        int single = (num % step) / (step/10);
                        step /=100;
                        if(step != 0) num %=(step*10);    

                        if(words !="")words += " ";



                        int total = ten * 10 + single;
                        switch(total){
                            case 10: words += "Ten" ; break;
                            case 11: words += "Eleven" ; break;
                            case 12: words += "Twelve" ; break;
                            case 13: words += "Thirteen" ; break;
                            case 14: words += "Fourteen" ; break;
                            case 15: words += "Fifteen" ; break;
                            case 16: words += "Sixteen" ; break;
                            case 17: words += "Seventeen" ; break;
                            case 18: words += "Eighteen" ; break;
                            case 19: words += "Nineteen" ; break;
                        }

                        if(ten != 1){
                            switch(ten){
                                case 2: words += "Twenty" ; break;
                                case 3: words += "Thirty" ; break;
                                case 4: words += "Forty" ; break;
                                case 5: words += "Fifty" ; break;
                                case 6: words += "Sixty" ; break;
                                case 7: words += "Seventy" ; break;
                                case 8: words += "Eighty" ; break;
                                case 9: words += "Ninety" ; break;
                            }

                            switch(single){
                                case 1: words += " One" ; break;
                                case 2: words += " Two" ; break;
                                case 3: words += " Three" ; break;
                                case 4: words += " Four" ; break;
                                case 5: words += " Five" ; break;
                                case 6: words += " Six" ; break;
                                case 7: words += " Seven" ; break;
                                case 8: words += " Eight" ; break;
                                case 9: words += " Nine" ; break;
                            }
                        }



                        switch(step){
                            case 10: words += " Hundred" ; break;
                            case 100: words += " Thousand" ; break;
                            case 100000: words += " Million"  ; break;
                        }



                    }else{
                        if(words !="")words += " ";
                            int Number = num / step;
                            switch(Number){
                                case 1: words += "One" ; break;
                                case 2: words += "Two" ; break;
                                case 3: words += "Three" ; break;
                                case 4: words += "Four" ; break;
                                case 5: words += "Five" ; break;
                                case 6: words += "Six" ; break;
                                case 7: words += "Seven" ; break;
                                case 8: words += "Eight" ; break;
                                case 9: words += "Nine" ; break;
                            }

                            switch(step){
                                case 100: words += " Hundred" ; break;
                                case 1000: words += " Thousand"  ; break;
                                case 100000: words += " Hundred" ; break;
                                case 1000000: words += " Million"  ; break;
                                case 100000000: words += " Hundred" ; break;
                                case 1000000000: words += " Billion"  ; break;
                            }

                            int thousand = (num / 1000 )%100; 
                            int million = (num / 1000000) % 100 ;
                            if((thousand == 0 && num <1000000 ) || (million == 0 && num > 1000000  )){
                                switch(step){
                                    case 100000 : words += " Thousand"; break;
                                    case 100000000 : words+= " Million" ; break;
                                }
                            }
                           num %=step;

                            step /= 10;
                    }
                }else{
                step /= 10;
                }
            }

            std::cout<<'\"' << words << '\"' << std::endl;

    return 0;
}