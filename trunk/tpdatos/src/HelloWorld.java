import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import spider.AbstractResultPagesSpider;
import spider.sites.buscape.BuscapeResultPagesSpider;
import dto.CategoryDto;
import dto.ProductDto;
import dto.ResultPageDto;
import exceptions.BusinessException;
import exceptions.spider.SpiderException;

public class HelloWorld extends ControllerServlet {

	private static final long serialVersionUID = 5132936917759337060L;

	@Override
	protected String doContent(HttpServletRequest request,HttpServletResponse response) throws BusinessException, SpiderException {
		AbstractResultPagesSpider spider = new BuscapeResultPagesSpider();
		
		StringBuffer strBuf = new StringBuffer();
		
		CategoryDto categoryDto = new CategoryDto();
		categoryDto.setName("filmadora");
		categoryDto = spider.spiderCategory(categoryDto);

		Integer totalProductsQty = 0;
		Integer currentProductsQty = 0;
		Integer totalResultPagesQty = categoryDto.getResultPageList().size();
		for (ResultPageDto resultPageDto : categoryDto.getResultPageList()) {
			currentProductsQty = resultPageDto.getQtyLinks();
			totalProductsQty += currentProductsQty;
			strBuf.append("<br>");
			strBuf.append("["+categoryDto.getName()+"] - ["+currentProductsQty+" productos] - " +
					"[pagina "+resultPageDto.getPageNumber()+"/"+totalResultPagesQty+"]");
			for (ProductDto productDto : resultPageDto.getProductList()) {
				strBuf.append("<br>");
				strBuf.append("["+productDto.getUrl()+"]");
			}
		}
		strBuf.append("<br>Total de productos: "+totalProductsQty);
		
		return strBuf.toString();
	}
}