
#ifndef CVAST_VIEWABLEIMPRESSION_HPP
#define CVAST_VIEWABLEIMPRESSION_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct ViewUndetermined : VB<ViewUndetermined> {
            URL value;

            ViewUndetermined () : VB("", A_URL, true, &(this->value)) {}
        };

        struct NotViewable : VB<NotViewable> {
            URL value;

            NotViewable () : VB("", A_URL, true, &(this->value)) {}
        };

        struct Viewable : VB<Viewable> {
            URL value;

            Viewable () : VB("", A_URL, true, &(this->value)) {}
        };

        struct ViewableImpressionAttrs {
            string id;
        };

        struct ViewableImpression : VB<ViewableImpression> {
            ViewableImpressionAttrs attrs;
            vector<NotViewable> notViewable;
            vector<Viewable> viewable;
            vector<ViewUndetermined> viewUndetermined;

            ViewableImpression () {
                {
                    NodeWrapper<NotViewable, vector<NotViewable>> wrapper("notViewable", true, false, this->notViewable);
                    this->childs.insert(make_pair("VIEWABLE", wrapper));
                }

                {
                    NodeWrapper<Viewable, vector<Viewable>> wrapper("viewable", true, false, this->viewable);
                    this->childs.insert(make_pair("VIEWABLE", wrapper));
                }

                {
                    NodeWrapper<ViewUndetermined, vector<ViewUndetermined>> wrapper("viewUndetermined", true, false, this->viewUndetermined);
                    this->childs.insert(make_pair("VIEWUNDETERMINED", wrapper));
                }

                this->symbols.emplace_back("id", A_STRING, false, &(this->attrs.id));
            }
        };


    }
}

#endif //CVAST_VIEWABLEIMPRESSION_HPP
