

#include <DataFrame/DataFrame.h>
#include <DataFrame/DataFrameStatsVisitors.h>
#include <DataFrame/RandGen.h>

#include <iostream>

using namespace hmdf;

constexpr std::size_t   ALIGNMENT = 256;

typedef StdDataFrame256<time_t> MyDataFrame;

// -----------------------------------------------------------------------------

int main(int, char *[]) {

    std::cout << "Starting ... " << std::endl;

    const auto  first = time(nullptr);
    auto        index_vec =
        MyDataFrame::gen_datetime_index("01/01/1980", "08/15/1981",
                                        time_frequency::secondly, 1);
    const auto  index_sz = index_vec.size();
    MyDataFrame df;

    df.load_data(
        std::move(index_vec),
        std::make_pair("normal", gen_normal_dist<double, ALIGNMENT>(index_sz)),
        std::make_pair("log_normal", gen_lognormal_dist<double, ALIGNMENT>(index_sz)),
        std::make_pair("exponential", gen_exponential_dist<double, ALIGNMENT>(index_sz)));

    const auto  second = time(nullptr);

    std::cout << "All data loadings are done. Calculating means ... "
              << second - first << std::endl;

    MeanVisitor<double, time_t> n_mv;
    MeanVisitor<double, time_t> ln_mv;
    MeanVisitor<double, time_t> e_mv;

    auto    fut1 = df.visit_async<double>("normal", n_mv);
    auto    fut2 = df.visit_async<double>("log_normal", ln_mv);
    auto    fut3 = df.visit_async<double>("exponential", e_mv);

    std::cout << fut1.get().get_result() << ", "
              << fut2.get().get_result() << ", "
              << fut3.get().get_result() << std::endl;

    const auto  third = time(nullptr);

    std::cout << third - second << ", " << third - first
              << " All done" << std::endl;
    return (0);
}

// -----------------------------------------------------------------------------

// Local Variables:
// mode:C++
// tab-width:4
// c-basic-offset:4
// End:
